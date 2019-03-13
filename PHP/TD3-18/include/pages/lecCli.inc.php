<?php
	$pdo=new Mypdo();
	$clientManager = new ClientManager($pdo);
	$clients=$clientManager->getAllClient();
	?>
	<div class="sstitre"><h2>Liste des clients</h2></div>

	<table>
		<tr><th>Numéro</th><th>Nom</th><th>Prénom</th></tr>
		<?php
		foreach ($clients as $client){ ?>
			<tr><td><?php echo $client->getCliNum();?>
			</td><td><?php echo $client->getNom();?>
			</td><td><?php echo $client->getPrenom();?>
			</td></tr>
		<?php } ?>
		</table>
		<br />
