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
