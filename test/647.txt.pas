program tju1211;
const
  maxm=10;
  maxlines=60;
  bit:array[1..10]of word=(512,256,128,64,32,16,8,4,2,1);
var
  max:array[1..maxm]of byte;
  line:array[1..maxlines]of word;
  count:array[1..maxlines]of byte;
  ok:array[0..2,0..maxlines]of byte;
  best:array[boolean,1..maxlines,1..maxlines]of word;
  lines,n,m,i,j,k,l,now,o1,o2,o3:word;
  b1,b2:boolean;
  c:char;
procedure search(l,x,c:word);
  begin
    if l>maxm then begin inc(lines);line[lines]:=x;count[lines]:=c;exit;end;
    search(l+1,x,c);
    search(l+3,x+bit[l],c+1);
  end;
begin
  search(1,0,0);
  max[1]:=2;max[2]:=3;max[3]:=4;
  for i:=4 to maxm do max[i]:=max[i-1]+max[i-3];

  repeat
    fillchar(ok,sizeof(ok),0);
    fillchar(best,sizeof(best),0);
    readln(n,m);lines:=max[m];
    ok[2,0]:=1;ok[2,1]:=1;ok[0,0]:=1;ok[0,1]:=1;
    o1:=0;o2:=2;b1:=false;

    for i:=1 to n do begin
      o3:=o2;o2:=o1;o1:=i mod 3;b2:=b1;b1:=odd(i);
      now:=0;for j:=1 to m do begin read(c);now:=now*2+ord(c='H');end;readln;
      ok[o1,0]:=0;
      for j:=1 to lines do
        if now and line[j]=0 then begin
          inc(ok[o1,0]);ok[o1,ok[o1,0]]:=j;
        end;
      fillchar(best[b1],sizeof(best[b1]),0);
      for j:=1 to ok[o1,0] do
        for k:=1 to ok[o2,0] do begin
          if line[ok[o1,j]] and line[ok[o2,k]]>0 then continue;
          for l:=1 to ok[o3,0] do begin
            if line[ok[o1,j]] and line[ok[o3,l]]>0 then continue;
            if line[ok[o2,k]] and line[ok[o3,l]]>0 then continue;
            if best[b2,l,k]>best[b1,k,j] then best[b1,k,j]:=best[b2,l,k];
          end;
          inc(best[b1,k,j],count[ok[o1,j]]);
        end;
    end;

    k:=0;
    for i:=1 to ok[o2,0] do
      for j:=1 to ok[o1,0] do
        if best[b1,i,j]>k then k:=best[b1,i,j];
    writeln(k);
  until seekeof;
end.

