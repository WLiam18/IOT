import paho.mqtt.client as mqtt

broker = "broker.hivemq.com"
topic = "test/topic"

def handle_message(client, userdata, msg):
    print("Received:", msg.payload.decode())

client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
client.on_message = handle_message

client.connect(broker, 1883)
client.subscribe(topic)

print("Listening for messages...")

client.loop_forever()

    
