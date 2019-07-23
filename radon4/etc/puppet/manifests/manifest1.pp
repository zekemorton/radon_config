#node 'radon4' {
	include redis
	include ::rabbitmq
#}

#package { 'rabbitmq-server':
#	ensure => 'installed',
#}

class rabbitmq_server_profile {
class { 'rabbitmq::server':
  service_manage    => true,
  service_ensure    => 'running',
  port              => '5660',
  delete_guest_user => true,
}
}
