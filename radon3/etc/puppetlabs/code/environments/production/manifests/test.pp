
  


-> class { 'rabbitmq::server':
  delete_guest_user => true,
#  version           => '2.4.1',
}

-> rabbitmq_user { 'zeke':
  admin    => true,
  password => 'password',
  provider => 'rabbitmqctl',
}

-> rabbitmq_vhost { 'zeke':
  provider => 'rabbitmqctl',
}

rabbitmq_user_permissions { 'zeke@zeke':
  configure_permission => '.*',
  read_permission      => '.*',
  write_permission     => '.*',
  provider             => 'rabbitmqctl',
}
