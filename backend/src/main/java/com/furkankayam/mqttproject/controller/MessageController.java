package com.furkankayam.mqttproject.controller;

import com.furkankayam.mqttproject.dto.request.MessageDto;
import com.furkankayam.mqttproject.service.MessageService;
import lombok.RequiredArgsConstructor;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api/messages")
@RequiredArgsConstructor
@CrossOrigin(origins = "*", allowedHeaders = "*")
public class MessageController {

    private final MessageService messageService;


    //CREATE
    @PostMapping
    public ResponseEntity<MessageDto> createMessage(@RequestBody MessageDto messageDto) throws MqttException {
        return new ResponseEntity<>(messageService.createMessage(messageDto), HttpStatus.OK);
    }

}
