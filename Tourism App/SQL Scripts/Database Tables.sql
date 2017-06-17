create table users
( user_id int, user_name varchar(30), 
user_password varchar(30), primary key (user_id));

create table weather 
( weather_region varchar(30), min_temp int ,
max_temp int, min_rainfall int, max_rainfall int,
primary key (weather_region));

create table place 
( place_id int auto_increment, place_name varchar(30), location varchar(30),
Address varchar(200), latitude varchar(30), longitude varchar(30),
category varchar(30), description varchar(200), primary key (place_id), foreign key (location) references weather(weather_region));



create table accomodation
( acco_id int auto_increment, acco_name varchar(30), 
 location varchar(30), type varchar(30), address varchar(300), min_cost int, 
max_cost int,  offers varchar(200), phone varchar(100),
primary key (acco_id), email varchar(50), website varchar(50),
foreign key (location) references weather(weather_region));



create table restaurant 
( res_id int auto_increment, primary key (res_id),
res_name varchar(30), location varchar(30), address varchar(300),
phone varchar(100), email varchar(50),
website varchar(50), description  varchar( 200),
foreign key (location) references weather(weather_region));

create table shopping_mall
( sp_id int  auto_increment, primary key (sp_id),
sp_name varchar(30), category varchar(30),
location varchar(30), address varchar(200),
foreign key (location) references weather(weather_region));


create table emergency 
( emr_id  int  auto_increment, primary key (emr_id), emr_name varchar(50),
emr_type varchar(30),location varchar(30), address varchar(200),phone varchar(100), email varchar(50), website varchar(50), foreign key (location) references weather(weather_region));


create table transportation
( tran_id int  auto_increment, primary key (tran_id), tran_name varchar(30),
category varchar(30), area varchar(100), 
phone varchar(100), email varchar(50), website varchar(50), address varchar(200),  foreign key (area) references weather(weather_region));


create table project_users
( u_id int auto_increment, primary key (u_id), u_name varchar(30), 
u_password varchar(30),
u_phone varchar(20), u_email varchar(30)
); 


create table photo
(photo_id int auto_increment, primary key (photo_id), place_id int, 
image longblob, filename varchar(255), mimetype varchar(255), foreign key(place_id ) references place(place_id));

create table booking
( booking_id int auto_increment, primary key (booking_id),
u_id int, acco_id int, booking_date date,
foreign key(u_id ) references project_users(u_id),
foreign key(acco_id ) references accomodation(acco_id)
);
