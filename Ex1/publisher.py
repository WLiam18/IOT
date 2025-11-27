import paho.mqtt.client as mqtt

broker = "broker.hivemq.com"
topic = "test/topic"

client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
client.connect(broker, 1883)

while True:
    msg = input("Enter message to send: ")
    client.publish(topic, msg)
    print("Message Published")


#pip install paho-mqtt 
