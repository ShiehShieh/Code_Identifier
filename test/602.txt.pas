program number;
const aim:array[1..8]of longint=(276951438,294753618,438951276,492357816,618753294,672159834,816357492,834159672);
var bu,zheng:array[1..400000]of longint;
    a,i,j,k,l,n:longint;
    q,v:boolean;
    g:array[1234567..9876543,0..1]of boolean;
procedure swap(o,p:longint);
var i,b,c,bw,cw,new:longint;
begin
  new:=0;
  b:=zheng[l];
  c:=zheng[l];
  bw:=1;
  cw:=1;
  for i:=1 to 9-o do
    begin
      bw:=bw*10;
      b:=b div 10;
    end;
  b:=b mod 10;
  for i:=1 to 9-p do
    begin
      cw:=cw*10;
      c:=c div 10;
    end;
  c:=c mod 10;
  new:=zheng[l]-b*bw+c*bw-c*cw+b*cw;
  if (new div 10 mod 10>new mod 10)and (g[new div 100,0]) then exit;
  if (new div 10 mod 10<new mod 10)and (g[new div 100,1]) then exit;
  n:=n+1;
  zheng[n]:=new;
  if (new div 10 mod 10>new mod 10)then g[new div 100,0]:=true;
  if (new div 10 mod 10<new mod 10)then g[new div 100,1]:=true;
  bu[n]:=bu[l]+1;
  for i:=1 to 8 do
    begin
      if aim[i]=zheng[n] then
        begin
          writeln(bu[n]);
          q:=true;
          exit;
        end;
    end;
end;
begin
  while not eof do
    begin
      fillchar(bu,sizeof(bu),0);
      fillchar(zheng,sizeof(zheng),0);
      fillchar(g,sizeof(g),false);
      q:=false;
      v:=false;
      for i:=1 to 3 do
        begin
          for j:=1 to 3 do
            begin
              read(a);
              zheng[1]:=zheng[1]*10+a;
            end;
        end;
      readln;
      n:=1;
      l:=0;
      if (zheng[l] div 10 mod 10>zheng[l] mod 10)then g[zheng[l] div 100,0]:=true;
      if (zheng[l] div 10 mod 10<zheng[l] mod 10)then g[zheng[l] div 100,1]:=true;
      for i:=1 to 8 do if zheng[1]=aim[i] then
          begin
            writeln(0);
            v:=true;
          end;
      if not(v)then
      repeat
        l:=l+1;
        for i:=1 to 9 do
          begin
            if i<=6then
              begin
                swap(i,i+3);
                if q then
                  begin
                    v:=true;
                    break;
                  end;

              end;
            if i mod 3<>0 then
              begin
                swap(i,i+1);
                  if q then
                    begin
                      v:=true;
                      break;
                    end;
               end;
          end;
        if v then break;
      until(l>n);
    end;
end.

