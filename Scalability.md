# Scalability & Memory Units

Scalability is a characteristic of cloud computing which is used to handle the increasing workload by increasing in proportion amount of resource capacity.


## Critical Points

### Requirement
 Inspect the requirements
- Functional
- Non Functional
- Extended functionality

### Capacity
How much the data that will be stored in the system? I/O process on the data along with the data growth? About estimation and growth of the system.

### API Design, Database Schema,

### Component Design

### High level system Design

If we are designing a system, the basic concepts we need are;

   – Client
   – Services
   – Web server
   – Application server
   – Picture Storage
   – Database
   – Caching
   – Replication
   – Redundancy
   – Load balancing
   – Sharding

### Replication & Redundancy

Replication is a very important concept to handle a failure of services or servers. Replication and redundancy basically mean the copy of services or servers. We can replicate database servers, web servers, application servers, image storages and etc.. Actually we can replicate all parts of the system. Notice that replication also helps system to decrease response time. You imagine, if we divide incoming requests into more resources rather than one resource, the system can easily meet all incoming requests. In addition, the optimum number of a replica to each resource is 3 or more. Thanks to replications, if any server dies, the system continues to respond via secondary resource.

### Data Sharding

As you know, sharding is a very important concept which helps system to keep data into different resources according to sharding process. There can be two sharding procedure to use.

### Caching

Cache memory is a crucial part of reading data faster. Cache memory usage can base on 80-20 rule. This means that cache capacity is the 20% of the daily data size. We can use LRU cache policy (Least Recently Used).

   -CDN: CDN, Content Delivery Network is for distributed file cache servers. We can usage CDN for keeping pictures.
   -Memcache / Redis: Keep metadata in the cache with Memcache or Redis.

### Load balancing

Load balancer allows incoming requests to be redirected to resources according to certain criteria. We can use load balancer at every layer of the system.

   – Between requests and web servers.
   – Between web servers and application servers.
   – Between application servers and databases
   – Between application servers and image storages.
   – Between application servers and cache databases.
