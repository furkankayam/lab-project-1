package com.furkankayam.mqttproject.repository;

import com.furkankayam.mqttproject.model.Message;
import org.springframework.data.jpa.repository.JpaRepository;

public interface MessageRepository extends JpaRepository<Message, Long> {
}
