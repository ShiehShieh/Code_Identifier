program xxx;
var s,xm,gb,xb:array[1..100] of string;
qm,bj,xh,jj,lw:array[1..100] of integer;
n,p,i,z:integer;
jxj:int64;
begin
readln(n);
for i:=1 to n do readln(s[i]);
for i:=1 to n do begin
    p:=pos(' ',s[i]);
     xm[i]:=copy(s[i],1,p-1);
     delete(s[i],1,p);
    p:=pos(' ',s[i]);
     val(copy(s[i],1,p-1),qm[i]);
     delete(s[i],1,p);
    p:=pos(' ',s[i]);
     val(copy(s[i],1,p-1),bj[i]);
     delete(s[i],1,p);
    p:=pos(' ',s[i]);
     gb[i]:=copy(s[i],1,p-1);
     delete(s[i],1,p);
    p:=pos(' ',s[i]);
     xb[i]:=copy(s[i],1,p-1);
     delete(s[i],1,p);
    val(s[i],lw[i]);
    xh[i]:=i;
end;
for i:=1 to n do begin
    if (qm[i]>80) and (lw[i]>0) then jj[i]:=jj[i]+8000;
    if (qm[i]>85) and (bj[i]>80) then jj[i]:=jj[i]+4000;
    if (qm[i]>90) then jj[i]:=jj[i]+2000;
    if (qm[i]>85) and (xb[i]='Y') then jj[i]:=jj[i]+1000;
    if (bj[i]>80) and (gb[i]='Y') then jj[i]:=jj[i]+850;
end;
z:=1;
for i:=2 to n do begin
    if (jj[i]>jj[z]) then z:=i else
       if (jj[z]=jj[i]) and (xh[i]=xh[z]) then z:=i;
end;
writeln(xm[z]);
writeln(jj[z]);
jxj:=0;
for i:=1 to n do jxj:=jxj+jj[i];
writeln(jxj);
end.
