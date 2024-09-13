import os;
import hashlib
import sys
import threading
import datetime
import json

checksum = ""
new_checksum = ""

running = True

class structure:
    def __init__(self,m_hash):
        self.time = datetime.date.today().strftime("%m-%d-%y")
        self.checksum = m_hash
        
        
def create_File(filename,hash):
    obj = structure(hash)
    
    with open(filename,'w') as file:
        file.write(f"{json.dumps(obj.__dict__)}\n\n")

        
def render_Data(m_file,m_data):
    obj = structure(m_data)

    try:
        mode = 'x' if(not os.path.exists(m_file)) else 'a'

        if('a' == mode):
            with open(m_file,mode) as file:
                file.write(f"{json.dumps(obj.__dict__)}\n")

        else:
            with open(m_file,mode) as file:
                create_File(m_file,m_data)

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
    BUILD = f"cmake --build ./build --config \"{sys.argv[1]}\""

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
        render_Data("cache.json",checksum)
        

event_checker = threading.Thread(target=get_changes)
event_checker.start()


while(running):

    command = input("> ")

    if(command.lower() == "exit"):
        running = False
        print("K bye")

    os.system("clear")
event_checker.join()