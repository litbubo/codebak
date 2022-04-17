CREATE TABLE SC (
	Sno CHAR ( 10 ),
	Cname CHAR ( 10 ),
	Grade NUMERIC ( 3 ),
	PRIMARY KEY ( Sno, Cname ),
	FOREIGN KEY ( Sno ) REFERENCES Student ( Sno ),

);