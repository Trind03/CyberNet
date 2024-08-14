import os;
import hashlib
import sys
import threading
import datetime
import json

checksum = ""
new_checksum = ""

running = True

def render_Data(m_file,m_data):
    class structure:
        def __init__(self,m_file, m_data):
            self.filename = m_file
            self.file_hash = m_data
            self.timestamp = datetime.now()
    try:
        mode = 'x' if(not os.path.exists(m_file)) else 'a'


        if(os.path.getsize(m_file) > 0):
            with open(m_file,mode) as file:
                obj = structure(m_file,m_data)
                file.write(json.dumps(obj))

        else:
            with open(m_file,mode) as file:
                obj = structure(m_file,m_data)
                file.write(json.dumps(obj))

    except Exception as e:
        print(f"error {e}")


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
        render_Data("cache.dat",checksum)
        

event_checker = threading.Thread(target=get_changes)
event_checker.start()


while(running):

    command = input("> ")

    if(command.lower() == "exit"):
        running = False
        print("K bye")

    os.system("clear")
event_checker.join()