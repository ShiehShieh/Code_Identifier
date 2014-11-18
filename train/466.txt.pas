program hhhhh;
type
        arr=array[1..10,1..10] of qword;
var
        a,b,c:arr;
        i,j,k,n:longint;
procedure init;
begin
        readln(k);
        readln(n);
end;

function cheng(a,b:arr):arr;
var
        i,j,x:longint;
begin
        for i:=1 to k do
          for j:=1 to k do begin
            c[i][j]:=0;
            for x:=1 to k do
              c[i,j]:=(c[i][j]+a[i][x]*b[x][j]) mod 7777777;
            end;
        cheng:=c;
end;

procedure run(i:longint);
begin
        if i=1 then begin a:=b;exit;end;
        run(i div 2);
        a:=cheng(a,a);
        if i mod 2=1 then a:=cheng(a,b);
end;

procedure work;
begin
        b[k][1]:=1;b[1][1]:=1;
        for i:=2 to k do b[i-1][i]:=1;
        for i:=1 to k do b[i][1]:=1;
        Run(n);
end;

procedure print;
begin
        writeln(a[1][1]);
end;

begin
        init;
        work;
        print;
end.


