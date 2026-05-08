class chatbot:
    def __init__(self):
        self.knowledgebase={
            "hello": "Hello! Welcome to ShopEasy.",
            "hi": "Hi! How can I assist you today?",
            "order": "Please provide your Order ID.",
            "refund": "Refunds are processed within 5-7 working days.",
            "return": "You can return products within 30 days.",
            "delivery": "Delivery usually takes 3-5 working days.",
            "payment": "We support UPI, Cards, and Net Banking.",
            "contact": "Contact us at support@shopeasy.com",
            "timing": "Our support is available from 9 AM to 9 PM.",
            "bye": "Thank you for visiting ShopEasy!"
        }
    def get_response(self,user_ip):
        user_ip=user_ip.lower()
        for keyword in self.knowledgebase:
            if keyword in user_ip:
                return self.knowledgebase[keyword]
        return "NO match found"

    def start(self):
        while True:
            user_ip=input("\nYOU:")
            if user_ip.lower()=="exit":
                print("Goodbye")
                break
            response=self.get_response(user_ip)
            print("Bot",response)
bot=chatbot()
bot.start()


