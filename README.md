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
              

<details>
<summary>Project Architecture & Development Plan</summary>

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



## Architecture

The program is divided into several components, each responsible for a specific part of the ping process.

```text
                         ft_ping
                            │
                            ▼
                    Command-line parsing
                            │
                            ▼
                  Hostname / IPv4 resolution
                            │
                            ▼
                     Raw ICMP socket
                            │
                 ┌──────────┴──────────┐
                 ▼                     ▼
          ICMP Echo Request       Receive packet
                 │                     │
                 ▼                     ▼
              sendto()              recvfrom()
                 │                     │
                 └──────────┬──────────┘
                            ▼
                    Parse ICMP response
                            │
                            ▼
                    Validate the packet
                            │
                 ┌──────────┴──────────┐
                 ▼                     ▼
             Valid reply          ICMP error
                 │                     │
                 ▼                     ▼
            Calculate RTT         Handle / display
                 │
                 ▼
              Display
                 │
                 ▼
             Statistics

             
Main Components
Command-Line Parsing

Responsible for:

Parsing the program arguments.
Handling the mandatory -v and -? options.
Validating the destination argument.
Address Resolution

Responsible for:

Accepting IPv4 addresses.
Resolving hostnames and FQDNs.
Preparing the destination sockaddr_in structure.
Raw Socket

The program uses an IPv4 raw socket with the ICMP protocol:

socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

Raw sockets allow ft_ping to construct and send ICMP packets directly.

ICMP Packet

The ICMP Echo Request contains:

Type
Code
Checksum
Identifier
Sequence number
Payload

The program calculates the checksum before sending the packet.

Packet Reception

The program waits for incoming packets using recvfrom().

Received packets are inspected to determine whether they contain:

The expected ICMP Echo Reply.
An ICMP error message.
An unrelated packet.

Only the appropriate response is associated with the request sent by ft_ping.

RTT Measurement

The Round-Trip Time is measured by recording timestamps around the packet transmission:

Timestamp 1
    │
    ├── send ICMP Echo Request
    │
    ├── network round trip
    │
    └── receive ICMP Echo Reply
          │
          ▼
      Timestamp 2

RTT = Timestamp 2 - Timestamp 1
Signal Handling

SIGINT is handled to allow the user to terminate the program with:

Ctrl+C

The program then stops sending packets and displays the final statistics.

Statistics

At termination, the program displays information such as:

Packets transmitted
Packets received
Packet loss
Total elapsed time
RTT statistics
Project Structure
ft_ping/
├── Makefile
├── README.md
├── includes/
│   └── ft_ping.h
└── src/
    ├── main.c
    ├── ping.c
    ├── packet.c
    ├── resolve.c
    ├── display.c
    └── utils.c

The source files are separated by responsibility to keep the project modular and easier to maintain and debug.
```

</details>

# 1 - Installed a minimal Debian 13.6.0 with the required packages and no graphical interface.

- gcc
- make
- gdb
- git
- openssh-server
- tmux (for multi windows)

tmux commands

ctr + b -> c (creats a new window)

[0] 0:bash* 1:bash- 2:bash

ctr + b -> 2  (select window 2, * show actived window)

ctr + b ->  % (split verticaly)
ctr + b - > " (split horizontal)

ctr + b -> d  (detached, exit without close all)

tmux attach

tmux atach-session



```
ATTENTION: Program in C, all libC is authorised, using the system
**`ping`** or the sources of a standard ping in any way is **`forbidden`**.
```



<details>
<summary>ICMP</summary>

ref: https://en.wikipedia.org/wiki/Internet_Control_Message_Protocol

ICMP (Internet Control Message Protocol) is a network protocol used to send error messages and diagnostic information between devices. It is commonly used by tools such as ping and traceroute.

<table>
<tr>
<th>Header IP</th>
<th>Message ICMP</th>
</tr>
<tr>
<td colspan="2">Datagram IP</td>
</tr>
</table>


<table>
<tr>
<th> Type (8 bits) </th>
<th> Code (8 bits) </th>
<th> Checksum (16 bits) </th>
</tr>
<tr>
<td colspan="3"> Message content (variable)</td> 
</tr>
</table>

</details>


<details>
<summary>Code</summary>

### parsing

getopt (without "_long")  for smal options like -h, -v.

*used: getopt_long watchs small (-h) and long options (--help), its GNU style.

```
signature

int getopt_long(int argc, char * const argv[],
                 const char *optstring,
                 const struct option *longopts, int *longindex);

```





</details>

 
