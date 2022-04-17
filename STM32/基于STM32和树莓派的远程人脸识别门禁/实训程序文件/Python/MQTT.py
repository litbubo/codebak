from paho.mqtt import client as mqtt_client

client = ''


def connect_mqtt():
    global client
    client = mqtt_client.Client("litbubo")
    client.connect('121.40.198.205', 1883, 60)
    client.loop_forever()


def publish(msg):
    result = client.publish("control", msg)
    status = result[0]
    if status == 0:
        print(f"Send msg to topic")
    else:
        print(f"Failed to send message to topic")


'''
def run():
    client = connect_mqtt()
    client.loop_forever()
    publish(client)

'''
