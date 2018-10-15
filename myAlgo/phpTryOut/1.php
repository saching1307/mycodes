<?php

function getHeuristicBasedValidations($battleType, $levelDifference) {
	$rulesForBattleHeuristics = Array(
			'FleetVsFleet'	=> array(
				'timeHeuristics' => array(
					//array(Minimum Score Diff, Expected Battle Time, margin of Error),
					86 => array(60,30),
					0 => array(200,100),
					),
				'healthHeuristics' => array(
					//array(Minimum Score Diff, Weaker Fleet Health Remaining, margin of Error in weak opponent health, Stronger Fleet Health Remaining, margin of Error in Strong opponent health),
					92 => array(0,2,100,2),
					0 => array(0,2,100,2),
					)
				),
			'FleetVsIsland'		=> array(
				'timeHeuristics' => array(
					//array(Minimum Score Diff, Expected Battle Time, margin of Error),
					86 => array(60,30),
					0 => array(200,100),
					),
				'healthHeuristics' => array(
					//array(Minimum Score Diff, Weaker Fleet Health Remaining, margin of Error in weak opponent health, Stronger Fleet Health Remaining, margin of Error in Strong opponent health),
					92 => array(0,2,100,2),
					0 => array(0,2,100,2),
					)
				)
				);


	$typesOfBattleHeuristics = array('timeHeuristics','healthHeuristics');
	$heuristics = $typesOfBattleHeuristics;
	$battleHeuristic = array();
	$battleHeuristic['battle_type'] = $battleType;
	foreach($heuristics as $key => $heuristicType) {
		$rules = $rulesForBattleHeuristics[$battleType][$heuristicType];
		print_r($rules);
		foreach($rules as $level => $rule) {
			echo "$level ". print_r($rule,true) ."\n";
			if($level <= $levelDifference) {
				if($heuristicType === 'healthHeuristics')  {
					$battleHeuristic['weak_health_remaining'] = $rule[0];
					$battleHeuristic['weak_health_remaining_error_marging'] = $rule[1];
					$battleHeuristic['strong_health_remaining'] = $rule[2];
					$battleHeuristic['strong_health_remaining_error_marging'] = $rule[3];
				}
				else if($heuristicType === 'timeHeuristics') {
					$battleHeuristic['time_error_margin'] = $rule[0];
					$battleHeuristic['battle_time_duration'] = $rule[1];
				}
				break;
			}
		}
	}
	return $battleHeuristic;
}

print_r(getHeuristicBasedValidations('FleetVsFleet',87));
?>
