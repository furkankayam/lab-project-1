package com.furkankayam.mqttproject.service.impl;

import com.furkankayam.mqttproject.dto.converter.MessageConverter;
import com.furkankayam.mqttproject.dto.converter.MqttConverter;
import com.furkankayam.mqttproject.dto.request.MessageDto;
import com.furkankayam.mqttproject.model.Message;
import com.furkankayam.mqttproject.model.MqttPublishModel;
import com.furkankayam.mqttproject.repository.MessageRepository;
import com.furkankayam.mqttproject.service.MessageService;
import com.furkankayam.mqttproject.service.MqttService;
import lombok.RequiredArgsConstructor;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.springframework.stereotype.Service;

@Service
@RequiredArgsConstructor
public class MessageServiceImpl implements MessageService {

    private final MessageRepository messageRepository;
    private final MessageConverter messageConverter;
    private final MqttConverter mqttConverter;
    private final MqttService mqttService;

    @Override
    public MessageDto createMessage(MessageDto messageDto) throws MqttException {
        Message message = messageConverter.toMessage(messageDto);
        messageRepository.save(message);
        MqttPublishModel mqttPublishModel = mqttConverter.toMqttModel(messageDto);
        mqttService.publishMessage(mqttPublishModel);
        return messageDto;
    }
}
