#include <pgmspace.h>

#define SECRET
#define THINGNAME "" //esp device name

const char WIFI_SSID[] = ""; //woki ssid
const char WIFI_PASSWORD[] = "";
const char AWS_IOT_ENDPOINT[] = "a3gozzilrkv83v-ats.iot.us-east-1.amazonaws.com";

// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";

// Device Certificate
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAOtCD3j3hbRJlIvsa8OupGmAmb5aMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yNDAyMTYxNzE0
NDVaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCp7w1WLphh0uMRBD7v
+painDOytE7DGk2mW2kDST8OB+hrChW8FMlBYSIz6dnSJKnYpnc1ySaX3P/n7Nf2
WX5uNXwTaHJDbjhHvtcrHamNE/8sYis37ITq/JgYDF6ZWpo+sD7q3TTrrU33YP5C
+2E5TXeD/LT5PxCDKLf5tnM1D2UsMr0bdaISBmYByBgiqupkXcwDPgihalAtwgz/
yQX00DizdcEzhw6BX5hs87O+INFRNySqBElwST4txhFVHidQ73IZLqvSDJ3muL/d
oIKTuv7i6umi8ff5ert/juI5+FwV+4ASwl4iWBUdyZ5BoWQS2tK7cdIYHwC845yY
hsjFAgMBAAGjYDBeMB8GA1UdIwQYMBaAFDYkhm3Rxij8RnUKRjx9CPvdlQrfMB0G
A1UdDgQWBBStlNXDVmnPmzEvF06lfuciD01JYDAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAMwQwNAA/W1qESddWHvhAmfdi
fXJ8ehZvLi60qYVfiQE6pEhhCutrriYrHKw4SutGCTquKH4ntQL70S5NwjsGAZnz
+pkK0VYF0t6alpL4Kj2dtGGNFszMHE+IpvVlq/GrWQx3h5RQr8/ziOQirX+7HSDi
tNEWYMfGCSacEWeKwdXXO5nRiuoxL8PbOEgaf3JedPxnWv9pzmvyarlXmQrNCl5C
bMqTsM7E+nnRaFM/AvzW4z91g35ard2Q2wjSLMtuA4jJKfblmJGGdlAVQU5JoNt4
Gq4nlBjPKCUZfsGFgbh5DLsSUpR3887qj8FeTrze9aPj5g2I2OOdhLDES7bqvQ==
-----END CERTIFICATE-----
)KEY";

// Device Private Key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEowIBAAKCAQEAqe8NVi6YYdLjEQQ+7/qWopwzsrROwxpNpltpA0k/DgfoawoV
vBTJQWEiM+nZ0iSp2KZ3Nckml9z/5+zX9ll+bjV8E2hyQ244R77XKx2pjRP/LGIr
N+yE6vyYGAxemVqaPrA+6t00661N92D+QvthOU13g/y0+T8Qgyi3+bZzNQ9lLDK9
G3WiEgZmAcgYIqrqZF3MAz4IoWpQLcIM/8kF9NA4s3XBM4cOgV+YbPOzviDRUTck
qgRJcEk+LcYRVR4nUO9yGS6r0gyd5ri/3aCCk7r+4urpovH3+Xq7f47iOfhcFfuA
EsJeIlgVHcmeQaFkEtrSu3HSGB8AvOOcmIbIxQIDAQABAoIBAGqAAFq/zw6X7Wjv
wUYDRb7ZqGjaKfaKmJmm9lRx5kuz1wymgGKkoFESQC5K5BGYmr3F7jZOP5qzjcpb
nCmvgtYtPPqo3du2yxzj1NQXvfhFzQmS6MUevVrMPcHslqkDqGGbcYMeaZk+vvtH
1XJDO3Z/P2T/zqfax018Cnk8yE06uCXsCl9uErBBwEm7MPviYjqWfZM7NzptK3qM
jqoVXtLt79BbiWMHRmO1oLZyOHRlLs3NGi9wMgXOzcnxdK4L0aRQWiSazSB1K1sX
XBGRyI3bRjTNgerYY6zVg3wki1GPWYRAgPzjVsbXozoHAVKMPGzkjJ0AD8FJFTxp
/CA0F+0CgYEA2TFeiTWuflNw25Ct7nh4szPjdDqbPGE8fgHhsLUJexF19ALIdQf1
n5LxL8h6junjU+/qU4MiteSxBzxSpAC/bIKPMHc8RVD6fZHzDVc+qgOJDu5p+gTP
1GKm2qN4DLqr//p2ICwx5QwZTziM8Q3rnSgRcUE0FEe4y42UwJMjrHcCgYEAyEwA
+JuyvsItf9lpU8+CeYZ5QeO+YzrsGL2vuX/lJt/oSM1NUfaSmjyr7IWdccAhErsL
+8Mfa+330N6+pZvR3smNReiYl/W6doqrSbiDejabFZgylc0AjBSsTE2OponlZ+Vu
vea/0cjphspXTQnwyHyr/WzS8AksxOqaOrozD6MCgYEAi9ij/EkaX7CuXFHeDEx5
uzlP3UjXJ5ucba4cecE3p4xonIMmO2SynNrqfU/iyh6DB0rVYIxxTxk/e181/u+U
UfQG6rf7kM5BW5UcIJzqdmHsYDbW+esbPq9+rAzRgbC4iwvj/3c1cTvHGCFbbuL9
sKVaBchsFhrQPBCflReowqUCgYB6RiuxmRsdaNzt14N9LoiwN29+0dFAMpA+6k2E
KJdzi+z5xJsXFjeZAMDTux3Ke0e1b4p5PzzHXpaSY+huoRkVsGUV8FB3NAOIqk62
ynU4/mzeWfNHj8ZtvZERY6dZ84SgUGeydlNTdhtZtdxlo1PikHlOVEjRUEiMTcup
XlIdkQKBgBSH9Bw0Gv0IGrFs2pn1Qfug16cDvKu1YPU4TKt5WvzstroMybkglu7h
1g3Wyaxe8mtv64l6s9spFTCUdzpsow9WUAdqPJwhpbx/lDsLXKXANv50YInUz/iC
8yfoLvxMypc+n4ByGKsyWs0quBK+PQNVzYUEB8gf+cU153CyyBAE
-----END RSA PRIVATE KEY-----
)KEY";