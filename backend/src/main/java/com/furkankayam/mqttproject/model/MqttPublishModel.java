package com.furkankayam.mqttproject.model;


import jakarta.validation.constraints.NotNull;
import jakarta.validation.constraints.Size;
import lombok.Data;

@Data
public class MqttPublishModel {

    @NotNull
    @Size(min = 1,max = 255)
    private String topic;

    @NotNull
    @Size(min = 1,max = 255)
    private String message;

    @NotNull
    private Boolean retained;

    @NotNull
    private Integer qos;

}
