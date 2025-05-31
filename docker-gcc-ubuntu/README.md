# ubuntu

Ubuntu with sshd

## build 
```
docker build -t gcc-ubuntu .
```

## run 
```
docker run -p 2222:22 -d -v $PWD/../:/root/c-practice -e ROOT_PASSWORD=123456 gcc-ubuntu
```
