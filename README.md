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

## Development Steps

The project will be developed progressively, starting from the basic ICMP communication and adding the required features step by step.

### 1. Raw Socket Creation
- Create a raw IPv4 socket using `AF_INET`, `SOCK_RAW`, and `IPPROTO_ICMP`.
- Handle socket creation errors and verify the required privileges.

### 2. ICMP Echo Request
- Build an ICMP Echo Request packet.
- Set the ICMP type, code, identifier, and sequence number.
- Prepare the packet payload.

### 3. ICMP Checksum
- Implement the ICMP checksum calculation.
- Insert the calculated checksum into the packet before sending it.

### 4. Send the Packet
- Resolve the destination IPv4 address or hostname.
- Send the ICMP Echo Request using `sendto()`.

### 5. Receive the Response
- Receive incoming packets using `recvfrom()`.
- Parse the received IP and ICMP headers.
- Identify the ICMP Echo Reply corresponding to the request sent by `ft_ping`.

### 6. Measure Round-Trip Time
- Record the time immediately before sending the packet.
- Record the time when the corresponding reply is received.
- Calculate and display the Round-Trip Time (RTT).

### 7. Packet Information
- Display the source IP address.
- Display the number of bytes received.
- Display the ICMP sequence number.
- Display the TTL.
- Display the RTT.

### 8. Hostname and FQDN Support
- Accept both IPv4 addresses and hostnames as arguments.
- Resolve hostnames using the appropriate libc networking functions.
- Support Fully Qualified Domain Names (FQDN).
- Do not perform reverse DNS resolution when processing received packets.

### 9. Command-Line Options
Implement the mandatory options:
- `-v` — verbose output, including relevant ICMP errors.
- `-?` — display usage information.

### 10. Error Handling
- Handle invalid hostnames and addresses.
- Handle socket and network errors.
- Handle unexpected or unrelated ICMP packets without crashing.
- Ensure the program never terminates unexpectedly due to invalid input or network conditions.

### 11. Signal Handling
- Handle `SIGINT` (`Ctrl+C`) correctly.
- Stop the ping loop cleanly.
- Display the final ping statistics.

### 12. Output and Compatibility
- Follow the output format and indentation of `inetutils-2.0`.
- Compare the behavior of `ft_ping` with the reference implementation.
- Ensure the mandatory requirements are fully functional before implementing any bonus features.

### 13. Testing
Test the program with:
- IPv4 addresses
- Valid hostnames
- FQDNs
- Invalid hostnames
- Unreachable destinations
- `-v`
- `-?`
- `Ctrl+C`
- Different network conditions


