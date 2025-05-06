from flask import Flask
from flask import request
import os
app = Flask(__name__)

@app.route("/", methods=['GET'])
def listDirectory():
    return os.listdir("root")

@app.route("/<fileName>", methods=['GET'])
def catFile(fileName):
    with open(f"root/{fileName}") as f:
        return ''.join(f.readlines())
    
@app.route("/<fileName>", methods=['PUT'])
def createUpdateFile(fileName):
    if os.path.exists(f"root/{fileName}"):
         with open(f"root/{fileName}", "w") as f:
            f.writelines([request.json["content"]])
            return '', 204
    else:
        with open(f"root/{fileName}", "x") as f:
            f.writelines([request.json["content"]])
            return '', 201

@app.route("/", methods=['POST'])
def createFile():
     with open(f"root/autoName{len(os.listdir('root'))}", "x") as f:
            f.writelines([request.json["content"]])
            return '', 201
     
@app.route("/<fileName>", methods=['DELETE'])
def deleteFile(fileName):
    os.remove(f"root/{fileName}")
    return '', 200


if __name__ == "__main__":
    app.run()