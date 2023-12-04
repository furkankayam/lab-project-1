import React from "react";
import axios from "axios";
import "./App.css";

const App = () => {
  const sendMessage = (message) => {
    const URL = "http://localhost:9393/api/messages";
    const body = { message: message };

    axios
      .post(URL, body)
      .then((response) => {
        console.log("Message sent:", response.data);
      })
      .catch((error) => {
        console.error("Error:", error);
      });
  };


  return (
    <div>
      <button   id="dur" onClick={() => sendMessage("0")}>
        Dur
      </button>
      <button id="ileri" onClick={() => sendMessage("1")}>
        Ileri
      </button>
      <button id="sag" onClick={() => sendMessage("2")}>
        Sağ
      </button>
      <button id="geri" onClick={() => sendMessage("3")}>
        Geri
      </button>
      <button id="sol" onClick={() => sendMessage("4")}>
        Sol
      </button>
    </div>
  );
};

export default App;