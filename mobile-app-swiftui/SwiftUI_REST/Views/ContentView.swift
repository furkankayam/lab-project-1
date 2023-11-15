import SwiftUI

struct ContentView: View {
    
    var body: some View {
        ZStack {
            Color.white
                .ignoresSafeArea()
            
            VStack(alignment: .center) {
                
                Button(action: {
                    
                    print("Yukarı yön tuşuna basıldı")
                    
                    let buttonData = ButtonData(message: .up)
                    if let jsonData = try? JSONEncoder().encode(buttonData) {
                        if let jsonString = String(data: jsonData, encoding: .utf8) {
                            print(jsonString)
                        }
                    }
                    
                    sendButtonData(data: buttonData)
                }) {
                    Image(systemName: "arrow.up")
                        .font(.largeTitle)
                        .foregroundColor(.white)
                        .padding()
                        .background(Color.blue)
                        .clipShape(Circle())
                }
                
                HStack {
                    
                    Button(action: {
                        
                        print("Sol yön tuşuna basıldı")
                        
                        let buttonData = ButtonData(message: .left)
                        if let jsonData = try? JSONEncoder().encode(buttonData) {
                            if let jsonString = String(data: jsonData, encoding: .utf8) {
                                print(jsonString)
                            }
                        }
                        
                        sendButtonData(data: buttonData)
                    }) {
                        Image(systemName: "arrow.left")
                            .font(.largeTitle)
                            .foregroundColor(.white)
                            .padding()
                            .background(Color.blue)
                            .clipShape(Circle())
                    }
                    
                    Button(action: {
                        
                        print("Dur tuşuna basıldı")
                        
                        let buttonData = ButtonData(message: .stop)
                        if let jsonData = try? JSONEncoder().encode(buttonData) {
                            if let jsonString = String(data: jsonData, encoding: .utf8) {
                                print(jsonString)
                            }
                        }
                        
                        sendButtonData(data: buttonData)
                    }) {
                        Image(systemName: "stop.fill")
                            .font(.largeTitle)
                            .foregroundColor(.white)
                            .padding()
                            .background(Color.red)
                            .clipShape(Circle())
                    }
                    
                    
                    Button(action: {
                        
                        print("Sağ yön tuşuna basıldı")
                        
                        let buttonData = ButtonData(message: .right)
                        if let jsonData = try? JSONEncoder().encode(buttonData) {
                            if let jsonString = String(data: jsonData, encoding: .utf8) {
                                print(jsonString)
                            }
                        }
                        
                        sendButtonData(data: buttonData)
                    }) {
                        Image(systemName: "arrow.right")
                            .font(.largeTitle)
                            .foregroundColor(.white)
                            .padding()
                            .background(Color.blue)
                            .clipShape(Circle())
                    }
                    
                }
                
                Button(action: {
                    
                    print("Aşağı yön tuşuna basıldı")
                    
                    let buttonData = ButtonData(message: .down)
                    if let jsonData = try? JSONEncoder().encode(buttonData) {
                        if let jsonString = String(data: jsonData, encoding: .utf8) {
                            print(jsonString)
                        }
                    }
                    
                    sendButtonData(data: buttonData)
                }) {
                    Image(systemName: "arrow.down")
                        .font(.largeTitle)
                        .foregroundColor(.white)
                        .padding()
                        .background(Color.blue)
                        .clipShape(Circle())
                }
            
            }
        }
    }
}
