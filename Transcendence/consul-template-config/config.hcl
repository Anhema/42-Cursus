vault {
  address = "http://vault:8200"
  token   = "myroot"
  renew_token = false
}

template {
  source      = "/etc/consul-template/templates/env.ctmpl"
  destination = "/output/.env"
}
