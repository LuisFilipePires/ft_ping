# ft_ping
build your own ping command



                 ft_ping
                    │
                    ▼
             socket(AF_INET,
                    SOCK_RAW,
                    IPPROTO_ICMP)
                    │
                    ▼
             ICMP Echo Request
                    │
                    │ sendto()
                    ▼
                  Rede
                    │
                    ▼
             destino 8.8.8.8
                    │
                    ▼
             ICMP Echo Reply
                    │
                    │ recvfrom()
                    ▼
              ft_ping
                    │
                    ▼
              RTT / TTL

## 3. O que é um ICMP Echo Request

Quando fazemos:

ping 8.8.8.8

o ping envia um pacote ICMP Echo Request.

O destino responde com:

ICMP Echo Reply

A estrutura ICMP que vamos construir contém essencialmente:

0                   1                   2                   3
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|     Type      |     Code      |          Checksum             |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|           Identifier          |        Sequence Number        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                         Data ...                              |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

Para um Echo Request:

Type = 8
Code = 0

Para o Echo Reply:

Type = 0
Code = 0

---


