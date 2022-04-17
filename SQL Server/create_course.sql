CREATE TABLE Course
	(
	Cno CHAR(5),
	Cname CHAR(20) NOT NULL,
	Cpno CHAR(5),
	Ccredit NUMERIC(2),
	FOREIGN KEY(Cpno) REFERENCES Course(Cno),
	PRIMARY KEY (Cno)
);