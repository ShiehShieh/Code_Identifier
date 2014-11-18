var
  f : array [0..200,0..40] of longint;
  i,j,k,u,p,s : longint;
  dic : array [1..6] of string;
  word : array [1..200,1..200] of longint;
  st,str : string;

function max(a,b:longint):longint;
begin
  max:=a;
  if b>a then
    max:=b;
end;

procedure clear;
var
  i,j,p : longint;
  flag : array [1..6] of boolean;
begin
  for i:=1 to 6 do flag[i]:=true;
  for i:=1 to s do
    for j:=1 to s do
      if i<>j then
        if pos(dic[i],dic[j])=1 then
          if dic[i]<>dic[j] then
            flag[j]:=false
          else
            if flag[i] and flag[j] then
              flag[j]:=false;
  p:=0;
  for i:=1 to s do
    if flag[i] then begin
      inc(p);
      dic[p]:=dic[i];
    end;
  s:=p;
end;

function find(st:string):longint;
var
  i,j,k:longint;
begin
  find:=0;
  for i:=1 to s do
    for j:=1 to length(st)-length(dic[i])+1 do
      if copy(st,j,length(dic[i]))=dic[i] then
        inc(find);
end;

begin
  read(p,k);str:='';
  readln;
  for i:=1 to p do begin
    readln(st);
    str:=str+st;
  end;
  readln(s);
  for i:=1 to s do
    readln(dic[i]);
  clear;
  for i:=1 to p*20 do
    for j:=i to p*20 do
      word[i,j]:=find(copy(str,i,j-i+1));
  for i:=1 to p*20 do
    for j:=1 to k do
      for u:=j to i do
        f[i,j]:=max(f[i,j],f[u-1,j-1]+word[u,i]);
  writeln(f[p*20,k]);
end.
