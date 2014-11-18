{
ID:shadow_3
PROG:p1079
LANG:PASCAL
}

type
	bttype=record
		data,num,lc,rc:longint;
	end;

var
	rp,hsize,i,j,lc,rc,ans:longint;
	heap,appear:array[0..1000]of longint;
	bt:array[0..1000]of bttype;
	s:ansistring;

procedure insert(x:longint);
var
	t,t1,tmp:longint;
begin
	inc(hsize);
	heap[hsize]:=x;
	t1:=hsize;
	t:=hsize div 2;
	while bt[heap[t]].num>bt[heap[t1]].num do
	begin
		tmp:=heap[t];
		heap[t]:=heap[t1];
		heap[t1]:=tmp;
		t1:=t;
		t:=t div 2;
	end;
end;

procedure fix(x:longint);
var
	tmp,min:longint;
begin
	min:=x;
	if (x*2<=hsize) and (bt[heap[x*2]].num<bt[heap[min]].num) then min:=x*2;
	if (x*2+1<=hsize) and (bt[heap[x*2+1]].num<bt[heap[min]].num) then min:=x*2+1;
	if min=x then exit;
	tmp:=heap[x];
	heap[x]:=heap[min];
	heap[min]:=tmp;
	fix(min);
end;

function pop:longint;
begin
	pop:=heap[1];
	heap[1]:=heap[hsize];
	dec(hsize);
	fix(1);
end;

procedure dfs(dep,t:longint);
begin
        if t=0 then exit;
	if bt[t].data<>0
		then inc(ans,dep*bt[t].num)
		else begin
			dfs(dep+1,bt[t].lc);
			dfs(dep+1,bt[t].rc);
		end;
end;

begin


        heap[0]:=0;

	repeat
		readln(s);
		if s='END' then exit;
		fillchar(appear,sizeof(appear),0);
		for i:=1 to length(s) do inc(appear[ord(s[i])]);
		rp:=0;
                bt[0].num:=-100;
		hsize:=0;
		for i:=0 to 128 do if appear[i]<>0 then
		begin
			inc(rp);
			bt[rp].lc:=0;
			bt[rp].rc:=0;
			bt[rp].data:=i;
			bt[rp].num:=appear[i];
			insert(rp);
		end;
		if rp=1 then
		begin
			writeln(length(s)*8,' ',bt[1].num,' 8.0');
			continue;
		end;
		while hsize<>1 do
		begin
			lc:=pop;
			rc:=pop;
			inc(rp);
			bt[rp].lc:=lc;
			bt[rp].rc:=rc;
			bt[rp].data:=0;
			bt[rp].num:=bt[bt[rp].lc].num+bt[bt[rp].rc].num;
			insert(rp);
		end;
		ans:=0;
		dfs(0,heap[1]);
		writeln(length(s)*8,' ',ans,' ',length(s)*8/ans:0:1);
	until false;


end.

