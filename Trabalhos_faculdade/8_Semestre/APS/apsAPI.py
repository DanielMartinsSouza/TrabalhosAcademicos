from fastapi import FastAPI, HTTPException, Query
import uvicorn
import jwt
import datetime

app = FastAPI()

# https://www.kaggle.com/datasets/shivd24coder/pokemon-card-collection-dataset/

data = [
    {
        "id": 1,
        "content":{
            "id": "base1",
            "name": "Base Set",
            "logo": "https://assets.tcgdex.net/en/base/base1/logo",
            "cardCount": {
                "total": 102,
                "official": 102
            }
        }
    },
    {
        "id": 2,
        "content":{
            "id": "base2",
            "name": "Jungle",
            "logo": "https://assets.tcgdex.net/en/base/base2/logo",
            "symbol": "https://assets.tcgdex.net/univ/base/base2/symbol",
            "cardCount": {
                "total": 64,
                "official": 64
            }
        }
    },
    {
        "id": 3,
        "content":{
            "id": "basep",
            "name": "Wizards Black Star Promos",
            "logo": "https://assets.tcgdex.net/en/base/basep/logo",
            "symbol": "https://assets.tcgdex.net/univ/base/basep/symbol",
            "cardCount": {
                "total": 53,
                "official": 53
            }
        },
    },
    {
        "id": 4,
        "content":{
            "id": "wp",
            "name": "W Promotional",
            "cardCount": {
                "total": 7,
                "official": 7
            }
        },
    },
    {
        "id": 5,
        "content":{
            "id": "wp",
            "name": "W Promotional",
            "cardCount": {
                "total": 7,
                "official": 7
            }
        },
    },
]

@app.get("/")
def home():
    return {"data": len(data)}

# Rota para obter todos os dados com paginação
@app.get("/data/")
def get_all(skip: int = 0, limit: int = 10):
    return data[skip : skip + limit]

# Rota para obter um item específico
@app.get("/data/{item_id}")
def get_item(item_id: int):
    for item in data:
        if item['id'] == item_id:
            return item
    raise HTTPException(status_code=404, detail="Item não encontrado")

# Rota para adicionar dados
@app.post("/data/")
def add_data(item: dict):
    return data.append(item)

# Rota para atualizar dados
@app.put("/data/{item_id}")
def update_data(item_id: int, updated_item: dict):
    for i, item in enumerate(data):
        if item['id'] == item_id:
            data[i] = updated_item
            return {"message": "Dados atualizados com sucesso!"}
    raise HTTPException(status_code=404, detail="Item não encontrado")

# Rota para atualizar parcialmente dados
@app.patch("/data/{item_id}")
def partial_update_data(item_id: int, partial_item: dict):
    for i, item in enumerate(data):
        if item['id'] == item_id:
            data[i].update(partial_item)
            return {"message": "Dados atualizados parcialmente com sucesso!"}
    raise HTTPException(status_code=404, detail="Item não encontrado")

# Rota para excluir dados
@app.delete("/data/{item_id}")
def delete_data(item_id: int):
    global data
    data = [item for item in data if item['id'] != item_id]
    return {"message": "Dados excluídos com sucesso!"}

if __name__ == "__main__":

    secret_key2 = input(print("Insira a senha: "))

    def verify_token(token, secret_key):
        try:
            # Decodificar o token
            decoded_payload = jwt.decode(token, secret_key, algorithms=['HS256'])
            print('Token decodificado com sucesso!')
            print('Conteúdo do token:', decoded_payload)
            return True
        except jwt.ExpiredSignatureError:
            print('Token expirado. Faça login novamente.')
        except jwt.InvalidTokenError:
            print('Token inválido. Verifique suas credenciais.')
            return False

    # Defina a chave secreta para assinar o token
    secret_key = 'daniel123'

    # Criar um payload (dados que você deseja incluir no token)
    payload = {
        'user_id': 1,
        'username': 'daniel',
        'exp': datetime.datetime.utcnow() + datetime.timedelta(days=1)  # Tempo de expiração do token
    }

    # Criar o token JWT
    token = jwt.encode(payload, secret_key, algorithm='HS256')
    print(f'Token gerado: {token}')

    # Exemplo de uso:
    token_to_verify = token
    if(verify_token(token_to_verify, secret_key2) == True):
        uvicorn.run(app, host="127.0.0.1", port=8000)
    else:
        print("Impossivel conectar sem token")

