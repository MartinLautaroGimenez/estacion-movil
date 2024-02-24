import paho.mqtt.client as mqtt
import random

pepe = random.randint(1,3)
print(pepe)

# Definir las credenciales del broker MQTT
username = "etec"
password = "etec2024"

# Crear un cliente MQTT con un ID único
client = mqtt.Client(client_id="hY294oPAS2psa29")

# Establecer las credenciales de conexión
client.username_pw_set(username, password)

# Conectarse al servidor MQTT
client.connect("34.27.15.81", 1883)

# Publicar un mensaje
client.publish("topic/test", "Hola mundo")
client.publish("topic/test", pepe)

# Desconectarse del servidor MQTT
client.disconnect()
