
# parsetab.py
# This file is automatically generated. Do not edit.
# pylint: disable=W,C,R
_tabversion = '3.10'

_lr_method = 'LALR'

_lr_signature = 'PA PFPar : PA Par PF ParPar : '
    
_lr_action_items = {'PA':([0,2,4,],[2,2,2,]),'$end':([0,1,4,5,],[-2,0,-2,-1,]),'PF':([2,3,4,5,],[-2,4,-2,-1,]),}

_lr_action = {}
for _k, _v in _lr_action_items.items():
   for _x,_y in zip(_v[0],_v[1]):
      if not _x in _lr_action:  _lr_action[_x] = {}
      _lr_action[_x][_k] = _y
del _lr_action_items

_lr_goto_items = {'Par':([0,2,4,],[1,3,5,]),}

_lr_goto = {}
for _k, _v in _lr_goto_items.items():
   for _x, _y in zip(_v[0], _v[1]):
       if not _x in _lr_goto: _lr_goto[_x] = {}
       _lr_goto[_x][_k] = _y
del _lr_goto_items
_lr_productions = [
  ("S' -> Par","S'",1,None,None,None),
  ('Par -> PA Par PF Par','Par',4,'p_Par','par_yacc.py',20),
  ('Par -> <empty>','Par',0,'p_Par_empty','par_yacc.py',24),
]
