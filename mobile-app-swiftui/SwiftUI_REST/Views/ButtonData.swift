//
//  ButtonData.swift
//  SwiftUI_REST
//
//  Created by Şeymanur Köse on 30.10.2023.
//

import Foundation

enum ButtonType: String, Codable {
    case up = "1"
    case down = "3"
    case left = "4"
    case right = "2"
    case stop = "0"
}

struct ButtonData: Codable {
    var message: ButtonType
}

func sendButtonData(data: ButtonData) {

    guard let jsonData = try? JSONEncoder().encode(data) else {
        print("JSON verisine dönüştürme hatası")
        return
    }
    
    let url = URL(string: "http://10.210.2.220:8080/api/messages")!
    var request = URLRequest(url: url)
    request.httpMethod = "POST"
    request.setValue("application/json", forHTTPHeaderField: "Content-Type")
    
    request.httpBody = jsonData
    
    let task = URLSession.shared.dataTask(with: request) { data, response, error in
        guard let data = data, error == nil else {
            print(error?.localizedDescription ?? "Veri yok")
            return
        }
        
        let responseJSON = try? JSONSerialization.jsonObject(with: data, options: [])
        if let responseJSON = responseJSON as? [String: Any] {
            print(responseJSON)
        }
    }
    
    task.resume()
}





