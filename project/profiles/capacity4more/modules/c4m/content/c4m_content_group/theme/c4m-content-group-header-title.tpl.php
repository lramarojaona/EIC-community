<?php

/**
 * @file
 * Template for presenting additional information fields.
 *
 * Type, Status and Access at content group header title.
 */
?>

<?php if ($title): ?>
  <?php if ($homepage): ?>
    <h1 class="group-title">
      <?php print $title; ?>
    </h1>
  <?php else: ?>
    <div class="group-title">
      <?php print $title; ?>
    </div>
  <?php endif; ?>
<?php endif; ?>

<div class="group-indications">
  <div class="group-indications--access">
    <?php if ($group_access): ?>
      <i class="top-buffer group-icon group-<?php print $group_access; ?> node-icon as-group-<?php print $group_access; ?>"></i>
      <span class="top-buffer indication label label-access <?php print $group_access; ?> group-access">
        <?php print $group_access; ?>
      </span>
    <?php endif; ?>

    <?php if (count($organisations) || count($emails)): ?>
        <div class="restricted-organisation-icons <?php (empty($organisation_icons[0]))? print 'no-icons' : '';?>">
        <?php if ($organisation_icons): ?>
          <?php foreach ($organisation_icons as $organisation_icon): ?>
            <?php if ($organisation_icon): ?>
            <span class="restricted-organisation-icon">
              <?php print $organisation_icon; ?>
            </span>
            <?php endif; ?>
          <?php endforeach; ?>
        <?php endif; ?>

        <?php if (count($emails) || count($organisations) > 3): ?>
          <span class="group-organisation--more" data-toggle="collapse" data-target="#group-organisations">
            <span></span>
            <span></span>
            <span></span>
          </span>
        <?php endif; ?>
        </div>

      <div class="restricted-extra-wrapper collapse" id="group-organisations">
        <span class="extra-wrapper-close" data-toggle="collapse" data-target="#group-organisations">
          <span class="extra-wrapper-close-background"></span>
          <span class="extra-wrapper-close-bullet"></span>
          <span class="extra-wrapper-close-bullet"></span>
          <span class="extra-wrapper-close-bullet"></span>
        </span>

        <?php if (count($organisations)): ?>
          <div class="restricted-organisations">
            <ul>
              <?php foreach ($organisations as $organisation): ?>
                <li><?php print $organisation; ?></li>
              <?php endforeach; ?>
            </ul>
          </div>
        <?php endif; ?>
        <?php if (count($emails)): ?>
          <div class="restricted-emails">
            <ul>
              <?php foreach ($emails as $email): ?>
                <li><?php print $email; ?></li>
              <?php endforeach; ?>
            </ul>
          </div>
        <?php endif; ?>
      </div>
    <?php endif; ?>
  </div>

  <?php if ($group_type): ?>
    <span class="top-buffer indication label label-default group-type"><?php print $group_type; ?></span>
  <?php endif; ?>

  <?php if ($group_status): ?>
    <span class="top-buffer indication label group-status <?php print (!empty($label_type)) ? $label_type : ''; ?>"><?php print $group_status; ?></span>
  <?php endif; ?>
</div>
