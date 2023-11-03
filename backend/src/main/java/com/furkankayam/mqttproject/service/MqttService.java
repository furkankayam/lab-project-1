package com.furkankayam.mqttproject.service;

import com.furkankayam.mqttproject.model.MqttPublishModel;
import org.eclipse.paho.client.mqttv3.MqttException;

public interface MqttService {

    //MQTT-CREATE
    Void publishMessage(MqttPublishModel messagePublishModel) throws MqttException;

}
