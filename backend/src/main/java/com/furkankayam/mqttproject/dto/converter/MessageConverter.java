package com.furkankayam.mqttproject.dto.converter;

import com.furkankayam.mqttproject.dto.request.MessageDto;
import com.furkankayam.mqttproject.model.Message;
import org.springframework.context.annotation.Bean;
import org.springframework.stereotype.Component;

@Component
public class MessageConverter {

    public MessageDto toMessageDto(Message message) {
        MessageDto messageDto = new MessageDto();
        messageDto.setMessage(message.getMessage());
        return messageDto;
    }

    public Message toMessage(MessageDto messageDto) {
        Message message = new Message();
        message.setMessage(messageDto.getMessage());
        return message;
    }

}
