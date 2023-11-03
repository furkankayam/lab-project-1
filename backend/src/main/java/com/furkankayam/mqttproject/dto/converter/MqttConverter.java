package com.furkankayam.mqttproject.dto.converter;

import com.furkankayam.mqttproject.dto.request.MessageDto;
import com.furkankayam.mqttproject.model.Message;
import com.furkankayam.mqttproject.model.MqttPublishModel;
import org.springframework.stereotype.Component;

@Component
public class MqttConverter {

    public MqttPublishModel toMqttModel(MessageDto messageDto) {
        MqttPublishModel mqttPublishModel = new MqttPublishModel();
        mqttPublishModel.setMessage(messageDto.getMessage());
        mqttPublishModel.setQos(0);
        mqttPublishModel.setTopic("yon");
        mqttPublishModel.setRetained(true);
        return mqttPublishModel;
    }

}
