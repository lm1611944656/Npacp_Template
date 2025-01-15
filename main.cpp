#include <iostream>
#include <pcap.h>

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];

    // 获取系统上所有可用的网络设备
    pcap_if_t *alldevs;
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        std::cerr << "Error finding devices: " << errbuf << std::endl;
        return -1;
    }

    std::cout << "Available network devices:" << std::endl;

    // 遍历并显示所有网络设备
    pcap_if_t *device = alldevs;
    int i = 0;
    while (device) {
        std::cout << i++ << ": " << device->name << " - " << (device->description ? device->description : "No description available") << std::endl;
        device = device->next;
    }

    // 释放资源
    pcap_freealldevs(alldevs);
    return 0;
}
