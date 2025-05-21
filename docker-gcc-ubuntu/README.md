# ubuntu

Ubuntu with sshd

## build 
```
docker build -t gcc-ubuntu .
```

## run 
```
docker run -p 2222:22 -d $PWD/../:/root/c-practice gcc-ubuntu
```
