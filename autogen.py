import os;
import hashlib
import sys
import threading

checksum = ""
new_checksum = ""

running = True

def write_Data(m_data):
    print(m_data)


def getHash(path):
    hash = hashlib.md5()
    for root,dist,files in os.walk(path):
        for file in sorted(files):
            file_path = os.path.join(root,file)
            try:
                with open(file_path,'rb') as f:
                    while block := f.read(4):
                        hash.update(block)
            except Exception as e:
                print(f"Error cannot read {file_path}")
    return hash.hexdigest()


def get_changes():
    global running
    PRE_BUILD = f"cmake -B ./build -S . -G \"Unix Makefiles\""
    BUILD = f"cmake --build ./build --config \" {sys.argv[1]}\""

    checksum = ""
    new_checksum = ""

    while(running): 
        with threading.Lock(): 
            hashed_repo = getHash("./src/server") + getHash("./src/client")
            hash = hashlib.sha256(hashed_repo.encode("utf-8"))
            new_checksum = hash.hexdigest()
        
        if(checksum == new_checksum): continue
        else:
            os.system(PRE_BUILD)
            os.system(BUILD)

        with threading.Lock(): checksum = new_checksum
        

event_checker = threading.Thread(target=get_changes)
event_checker.start()


while(running):

    command = input("> ")

    if(command.lower() == "exit"):
        running = False
        print("K bye")

    os.system("clear")
event_checker.join()