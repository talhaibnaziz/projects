insert into weather 
values(10001, 20,35, 80,105, 'Khulna');

insert into weather 
values(10002, 21,39, 85,100, 'Bandarban');

insert into weather 
values(10003, 22,35, 87,110, 'Sylhet');


insert into place 
values( 10010,'Jaflong','Sylhet','84','85','Natural','Nice place',10003);

insert into place 
values( 10011,'Nilgiri','Bandarban','84','85','Natural','Just awesome!',10003);

insert into place 
values( 10012,'Sundarban','Khulna','84','85','Natural','Nice place',10003);


insert into accomodation 
values(11001, 'Hotel TT','Hotel', 'Sylhet',1000,5000,'10% in December','019*******','tt@gmailmail.com','www.tt.com');

insert into accomodation 
values(11002, 'Hotel Talnia','Motel', 'Bandarban',1000,5000,'10% in December','019*******','talnia@gmailmail.com','www.talnia.com');


insert into accomodation 
values(11003, 'Hotel Tasha','Hotel', 'Bandarban',1000,5000,'10% in December','019*******','tasha@gmailmail.com','www.tasha.com');


insert into restaurant
values( 12001, 'A new Restaurant','Bandarban','019*****','anr@gmail.com', 'www.anr.com','Well facilated');

insert into restaurant
values( 12002, 'Mid Night Restaurant','Khulna','019*****','mnr@gmail.com', 'www.mnr.com','Well facilated');

insert into restaurant
values( 12003, 'Mid Night Restaurant','Sylhet','019*****','mnr@gmail.com', 'www.mnr.com','Well facilated');

insert into shopping_mall
values(15001,'Talnia Plaza', 'shoppingmall','Bandarban');


insert into shopping_mall
values(15002,'Niata Plaza', 'shoppingmall','Khulna');


insert into shopping_mall
values(15003,'Tasha Plaza', 'shoppingmall','Sylhet');

//SECOND SHIFT

insert into photo (photo_id, place_id, image)
values( 10001, 10010, LOAD_FILE("1.png") );


insert into emergency
values (20001, 'Nigiri Health Complex', 'Health complex','Bandarban','019555352***', 'nhc@yahoo.com','www.nhc.com');

insert into emergency
values (20002, 'Jaflong model police station', 'Polic station','sylhet','019692***', 'jmps@gmail.com','www.jmps.com');

insert into emergency
values (20003, 'Kumarkhali fire service', 'Fire Servic','Khulna','019523***', 'kfr@gmail.com','www.kfr.com');

insert into emergency
values (20004, 'Nilgiri police station', 'Polic station','Bandarban','019692***', 'nps@gmail.com','www.nps.com');



insert into  transportation 
values(30001,'Hanif poribohon','bus','Bandarban','01869****','hanifp@gmail.com','www.hanifp.com');

insert into  transportation 
values(30002,'Ena poribohon','bus','Sylhet','018956***','enap@gmail.com','www.enap.com');

insert into  transportation 
values(30003,'Sylhet Railway','train','Sylhet','017562***','srw@gmail.com','www.srw.com');

insert into  transportation 
values(30004,'TT Travels','bus','Khulna','0195632***','ttt@gmail.com','www.ttt.com');




//THIRD SHIFT
insert into project_users (u_name, u_password, u_phone, u_email)
values('Shahriar','shahriar','01924****','shahriar@gmail.com');

insert into project_users (u_name, u_password, u_phone, u_email)
values('Talha','talha','01724****','talha@gmail.com');

insert into project_users (u_name, u_password, u_phone, u_email)
values('Sabbir','sabbir','01624****','sabbir@gmail.com');


insert into booking (u_id, acco_id, booking_date)
values(1,11001,'2016-11-05');

insert into booking (u_id, acco_id, booking_date)
values(1,11002,'2016-11-09');

insert into booking (u_id, acco_id, booking_date)
values(2,11003,'2016-11-06');

insert into booking (u_id, acco_id, booking_date)
values(3,11002, '2016-11-07');



insert into place_acco
values(10010,11001);


insert into place_acco
values(10011,11002);


insert into place_acco
values(10011,11003);


insert into place_res
values(10010,12003);


insert into place_res
values(10011,12001);


insert into place_res
values(10012,12002);

insert into place_emr
values(10011,20001);

insert into place_emr
values(10012,20003);

insert into place_emr
values(10011,20002);


insert into place_tran
values(10011,30001);



insert into place_tran
values(10010,30002);


insert into place_tran
values(10012,30004);


insert into place_tran
values(10010,30003);



insert into place_sp
values(10011,15001);


insert into place_sp
values(10012,15002);


insert into place_sp
values(10010,15003);

insert into users
values (1, 'admin1', 'rubel');

insert into users
values (2, 'admin2', 'talha');


