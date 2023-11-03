package com.furkankayam.mqttproject.config;

import org.eclipse.paho.client.mqttv3.IMqttClient;
import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttConnectOptions;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import java.util.UUID;

@Configuration
public class MqttConfig {

    private static final String MQTT_PUBLISHER_ID = UUID.randomUUID().toString();
    private static final String MQTT_SERVER_ADDRES= "tcp://192.168.1.85";
    private static IMqttClient instance;

    @Bean
    public IMqttClient getInstance() {
        try {
            instance = new MqttClient(MQTT_SERVER_ADDRES, MQTT_PUBLISHER_ID);

            MqttConnectOptions options = new MqttConnectOptions();
            /*options.setUserName("user-name");
            options.setPassword("password".toCharArray());*/
            options.setAutomaticReconnect(true);
            options.setCleanSession(true);
            options.setConnectionTimeout(10);

            if (!instance.isConnected()) {
                instance.connect(options);
            }
        } catch (MqttException e) {
            e.printStackTrace();
        }

        return instance;
    }

    public MqttConfig() {
    }
}
