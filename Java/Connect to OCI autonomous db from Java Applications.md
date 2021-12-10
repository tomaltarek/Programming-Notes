## How to Connect to Oracle Cloud Autonomous Database from Java Spring Projects 



#### Introduction

Connection to OCI autonomous database from java application is simple but tricky. In this article we will outline how to connect to oracle cloud database from a Spring/Spring boot or any java applications. There are two ways of making a connection- using jks or using wallet. 

We will use oracle wallet for the connection. 

#### Dependencies

We will require following jar files as dependencies. 

1. **ojdbc** - this jar file provide a mechanism for java applications to connect to database. 
2. **ucp** - this jar file is a single connection pool that handles all kinds of connections. This is hugely used in oracle products. 
3. **orclepki-** this jar file provides a secure architecture for safer exchange of information over internet. 
4. **ostd-core**- this jar file is required to access wallet from java
5. **ostd-cert** - this jar file is also responsible to access wallet from java. 

All these files can be downloaded from maven repository. Below is sample pom entries. 

```
<dependency>
   <groupId>com.oracle.database.jdbc</groupId>
   <artifactId>ojdbc8</artifactId>
 </dependency>
      <dependency>
          <groupId>com.oracle.database.jdbc</groupId>
          <artifactId>ucp</artifactId>
       </dependency>
 <dependency>
        <groupId>com.oracle.database.security</groupId>
        <artifactId>oraclepki</artifactId>
 </dependency> 

 <dependency>
        <groupId>com.oracle.database.security</groupId>
        <artifactId>osdt_core</artifactId>
  </dependency>

  <dependency>
        <groupId>com.oracle.database.security</groupId>
        <artifactId>osdt_cert</artifactId>
   </dependency>
```

#### Where to put your wallet file

Oracle wallet is downloadable from OCI. Download and unzip it. There is a ojdbc file, make sure the wallet information is uncommented if it is not. 

Then put the wallet folder under the resource folder of your java project. 

#### Connection String 

If you use application.properties file for your connection, the below is a sample of the entries of that file. 

```
spring.datasource.url=   jdbc:oracle:thin:@YourDbName_medium?TNS_ADMIN=src/main/resources/Wallet_YourDbName
spring.datasource.username=YourUserName
spring.datasource.password=YourPassword
spring.datasource.driverClassName=oracle.jdbc.driver.OracleDriver
```

That's pretty much it. A connection should be established. 
