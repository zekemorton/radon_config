#!/bin/bash

cp /conf/radon_config/radon1/etc/hosts /etc/hosts
cp /conf/radon_config/radon1/etc/hostname /etc/hostname
cp /conf/radon_config/radon1/etc/resolv.conf /etc/resolv.conf
cp /conf/radon_config/radon1/etc/sysconfig/network-scripts/ifcfg-em1 /etc/sysconfig/network-scripts/ifcfg-em1

systemctl restart network

parted /dev/sdb mklabel gpt
parted /dev/sdb mkpart primary xfs 0% 100%
mkfs -t xfs -f /dev/sdb1
mkdir -m 755 /tftpboot
echo '/dev/sdb1           /tftpboot       xfs    defaults        0 0'>> /etc/fstab
mount /tftpboot

yum update -y
yum install -y syslinux
yum install -y tftp-server
cp /usr/share/syslinux/* /tftpboot

mkdir /tftpboot/pxelinux.cfg
cp /conf/radon_config/radon1/tftpboot/pxelinux.cfg/default /tftpboot/pxelinux.cfg/default

mount /dev/sdc1 /mnt

mkdir /tftpboot/centos7
cp /mnt/images/pxeboot/initrd.img /tftpboot/centos7
cp /mnt/images/pxeboot/vmlinuz /tftpboot/centos7

yum install -y vsftpd
yum install -y tftp

cp /conf/radon_config/radon1/etc/vsftpd/vsftpd.conf /etc/vsftpd/vsftpd.conf

yum update -y
yum install -y syslinux
yum install -y tftp-server
cp /usr/share/syslinux/* /tftpboot

mkdir -p /tftpboot/ftp/pub
cp -r /mnt/*  /tftpboot/ftp/pub/

chmod -R 755 /tftpboot/ftp/pub

systemctl enable vsftpd
systemctl start vsftpd
systemctl status vsftpd

cp /conf/radon_config/radon1/etc/sysconfig/network-scripts/ifcfg-em2 /etc/sysconfig/network-scripts/ifcfg-em2

ifup em2

yum install -y dhcp

cp /conf/radon_config/radon1/etc/dhcp/dhcpd.conf /etc/dhcp/dhcpd.conf

systemctl enable dhcpd
systemctl start dhcpd

yum install -y xinetd
systemctl start xinted

cp /conf/radon_config/radon1/etc/xinetd.d/tftp /etc/xinetd.d/tftp

systemctl stop firewalld

restorecon -Rv /tftpboot

chcon -R -t public_content_t /tftpboot

yum install -y ftp

systemctl restart tftp
systemctl restart xinetd
systemctl restart vsftpd

cp /conf/radon_config/radon1/anaconda-ks.cfg /tftpboot/ftp/pub/
chmod 755 /tftpboot/ftp/pub/anaconda-ks.cfg

yum install -y pykickstart
ksvalidator /tftpboot/ftp/pub/anaconda-ks.cfg









