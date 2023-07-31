import serial.tools.list_ports

def scan_serial_ports():
    available_ports = list(serial.tools.list_ports.comports())
    if not available_ports:
        print("No serial ports detected.")
    else:
        for port in available_ports:
            print("Serial port found: " + port.device)

if __name__ == '__main__':
    scan_serial_ports()
