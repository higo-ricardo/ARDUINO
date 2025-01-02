
class Chatbot:
    def __init__(self):
        self.products = {
            "1": {"name": "Smartphone", "price": 1200.00},
            "2": {"name": "Laptop", "price": 2500.00},
            "3": {"name": "Headphones", "price": 150.00},
        }
        self.orders = []  # Lista para armazenar os pedidos do usuário
        self.all_orders = []  # Armazena todos os pedidos

    def show_menu(self):
        """Exibe o menu principal."""
        print("\n\nMENU PRINCIPAL")
        print("[1]. CONSULTA DE PREÇOS")
        print("[2]. FAZER UM PEDIDO")
        print("[3]. SAIR")

    def consult_prices(self):
        """Exibe os produtos disponíveis e seus preços."""
        print("\nLista de produtos e preços:")
        for code, product in self.products.items():
            print(f"Código: {code} | Produto: {product['name']} | Preço: R${product['price']:.2f}")

    def validate_quantity(self, quantity):
        """Valida se a quantidade fornecida é um número inteiro positivo."""
        try:
            qtd = int(quantity)
            if qtd > 0:
                return qtd
            else:
                print("A quantidade deve ser maior que zero.")
        except ValueError:
            print("Por favor, digite um número inteiro válido.")
        return None

    def place_order(self):
        """Permite que o usuário faça um novo pedido."""
        print("\nEssa funcionalidade ainda está em fase de testes, mas logo estará disponível!")
        
    def run(self):
        """Inicia o chatbot."""
        while True:
            self.show_menu()
            choice = input("\nEscolha uma opção: ")
            if choice == "1":
                self.consult_prices()
            elif choice == "2":
                self.place_order()
            elif choice == "3":
                print("\nObrigado por usar o chatbot. Até mais!")
                break
            else:
                print("Opção inválida. Tente novamente!")

# Instanciar e rodar o chatbot
chatbot = Chatbot()
chatbot.run()
