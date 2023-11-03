package com.furkankayam.mqttproject.service;

import com.furkankayam.mqttproject.dto.request.MessageDto;
import org.eclipse.paho.client.mqttv3.MqttException;

public interface MessageService {

    //CREATE
    MessageDto createMessage(MessageDto messageDto) throws MqttException;

}
