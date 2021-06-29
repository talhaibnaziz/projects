create table users
( user_id int, user_name varchar(30), 
password varchar(30), primary key (user_id));


create table weather 
( weather_id int, min_temp int ,
max_temp int, min_rainfall int, max_rainfall int,
weather_region varchar(30), primary key (weather_id));

create table place 
( place_id int, place_name varchar(30), Address varchar(200),
latitude varchar(30), longitude varchar(30), category varchar(30), description varchar(200),
primary key (place_id), weather_id int, foreign key (weather_id) references weather(weather_id));



create table accomodation
( acco_id int, acco_name varchar(30), 
type varchar(30), location varchar(200), min_cost int, 
max_cost int,  offers varchar(200), phone varchar(100),
primary key (acco_id), email varchar(50), website varchar(50));



create table restaurant 
( res_id int, primary key (res_id), res_name varchar(30), location varchar(100), 
phone varchar(100), email varchar(50), website varchar(50), description  varchar( 200));

create table shopping_mall
( sp_id int, primary key (sp_id), sp_name varchar(30), category varchar(30),
location varchar(200));


create table emergency 
( emr_id  int, primary key (emr_id), emr_name varchar(50),
emr_type varchar(30), address varchar(200),phone varchar(100), email varchar(50), website varchar(50));


create table transportation
( tran_id int, primary key (tran_id), tran_name varchar(30),
category varchar(30), area varchar(100), 
phone varchar(100), email varchar(50), website varchar(50));






create table place_acco
( place_id int, acco_id int, 
foreign key (place_id) references place (place_id),
foreign key ( acco_id) references accomodation (acco_id)); 


create table  place_res 
( place_id int, res_id int, 
foreign key(place_id) references place(place_id),
foreign key (res_id) references restaurant (res_id));


create table place_emr
(  place_id int, emr_id int, 
foreign key(place_id) references place (place_id),
foreign key (emr_id) references emergency(emr_id));


create table  place_tran
(  place_id int, tran_id int, 
foreign key(place_id) references place(place_id),
foreign key (tran_id) references transportation(tran_id));


create table  place_sp
(  place_id int, sp_id int, 
foreign key(place_id) references place(place_id),
foreign key (sp_id) references shopping_mall(sp_id));


create table project_users
( u_id int, primary key (u_id), u_name varchar(30), 
u_password varchar(30),
u_phone varchar(20), u_email varchar(30)
); 


create table photo
(photo_id int, primary key (photo_id), place_id int, 
image longblob, filename varchar(255), 
mimetype varchar(255),last_update_date date, 
foreign key(place_id ) references place(place_id)
);

create table booking
( booking_id int, primary key (booking_id), u_id int, acco_id int, booking_date date,
foreign key(u_id ) references project_users(u_id),
foreign key(acco_id ) references accomodation(acco_id)
);

create table temp
( temp_key int, primary key (temp_key), place_id int,
foreign key(place_id) references place(place_id));

create sequence project_seq start with 10001 increment by 1;




CREATE OR REPLACE FUNCTION project_auth 
(
p_username IN varchar,
    p_password IN varchar)

RETURN BOOLEAN IS
BEGIN
  FOR c1 IN 
(SELECT 1 
              FROM project_users
   
          WHERE upper(u_name) = upper(p_username)
  
             AND upper(u_password) = upper(p_password))

  LOOP
    RETURN TRUE;
  
END LOOP;
 
 RETURN FALSE;

END;

/
