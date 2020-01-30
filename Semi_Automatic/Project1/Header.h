class PointXYZ
{
public:
	double x;
	double y;
	double z;
};

class GetID{
public:
	int NO;
	char name[128];
};

class KmlFileXYZ{
public:
	int Id;
	double x;
	double y;
	double z;
	int Qflag;
	int Show;
	int FId;
};

class XYZarraytemp{
public:
	char  xyz[8192];

};
