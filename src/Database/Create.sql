CREATE TABLE "Streets" (
	"id" INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	"name" TEXT
);

CREATE TABLE "Street Nodes" (
	"id" INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	"street" INTEGER NOT NULL,
	"start latitude" REAL NOT NULL,
	"start longitude" REAL NOT NULL,
	"end latitude" REAL NOT NULL,
	"end longitude" REAL NOT NULL,
	FOREIGN KEY("street") REFERENCES Street("id")
);

CREATE TABLE "Addresses" (
	"id"	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	"street" INTEGER NOT NULL,
	"house_number"	INTEGER,
	"country"	TEXT NOT NULL,
	"state"	TEXT,
	"postal_code"	TEXT,
	"latitude" REAL NOT NULL,
	"longitude" REAL NOT NULL,
	FOREIGN KEY("street") REFERENCES Street("id")
);

CREATE TABLE "Points_of_Interest" (
	"id"	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	"address" INTEGER NOT NULL,
	"name"	TEXT,
	"type"	TEXT NOT NULL,
	"website"	TEXT,
	FOREIGN KEY("address") REFERENCES Address("id")
);

CREATE TABLE "Intersections" (
	"id"	INTEGER NOT NULL PRIMARY KEY,
	"street" INTEGER NOT NULL,
	FOREIGN KEY("street") REFERENCES Street("id")
);

CREATE UNIQUE INDEX IF NOT EXISTS id_index ON Streets(id);
CREATE UNIQUE INDEX IF NOT EXISTS id_index ON "Street Nodes"(id);
CREATE UNIQUE INDEX IF NOT EXISTS id_index ON Addresses(id);
CREATE UNIQUE INDEX IF NOT EXISTS id_index ON "Points of Interest"(id);
CREATE UNIQUE INDEX IF NOT EXISTS id_index ON Intersections(id);

CREATE INDEX IF NOT EXISTS name_index ON Streets(name);

CREATE INDEX IF NOT EXISTS name_index ON "Points of Interest"(name);
CREATE INDEX IF NOT EXISTS type_index ON "Points of Interest"(type);

CREATE INDEX IF NOT EXISTS street_index ON "Street Nodes"(street);

CREATE INDEX IF NOT EXISTS street_index ON "Addresses"(street);

CREATE INDEX IF NOT EXISTS street_index ON "Intersections"(street);
