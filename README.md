# Port Scanner
A port scanner is a software application designed to probe a server or host for open ports by sending packets to various TCP or UDP ports and analyzing the responses. This tool is commonly used by network administrators to verify security policies and by attackers to identify network services running on a host and exploit vulnerabilities. This a simple version of it with qt interface

## Explaintion
- Using socket application applied solid principles for clean code there is multible classes ```ServerCreation SocketCreation SocketConnection```
  
### SocketCreation
- This class resposible for SocketCreation and return socket resonse
  
### ServerCreation
- Is responsible for Create a server and handle if the ip address is invalid
  
### SocketConnection 
- Using those classes to connect to the server and socket created then check if the port is opend or not


![Screenshot from 2024-09-09 14-32-11](https://github.com/user-attachments/assets/f3cbf476-4049-4e7d-9d6f-ddcfc0eff268)
