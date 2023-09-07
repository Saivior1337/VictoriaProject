const checkboxes = [
    { id: 'is_aimbot_enabled', key: 'is_aimbot_enabled' },
    { id: 'is_trigger_enabled', key: 'is_trigger_enabled' },
    { id: 'is_misc_enabled', key: 'is_misc_enabled' },
    { id: 'checkbox_glow', key: 'checkbox_glow'},
    { id: 'checkbox_glow_enemy', key: 'checkbox_glow_enemy'},
    { id: 'checkbox_glow_friend', key: 'checkbox_glow_friend'},
    { id: 'checkbox_glowHealth', key: 'checkbox_glowHealth'},
    { id: 'checkbox_radar', key: 'checkbox_radar'},
    { id: 'checkbox_chams', key: 'checkbox_chams'},
    { id: 'checkbox_bhop', key: 'checkbox_bhop'},
    { id: 'checkbox_gpreview', key: 'checkbox_gpreview'},
    { id: 'checkbox_darkmap', key: 'checkbox_darkmap'},
    { id: 'checkbox_viewmodel', key: 'checkbox_viewmodel'},
    { id: 'checkbox_recoil_crosshair', key: 'checkbox_recoil_crosshair'},
    { id: 'checkbox_force_sniper_crosshair', key: 'checkbox_force_sniper_crosshair'},
    { id: 'checkbox_weapon_debug_accuracy', key: 'checkbox_weapon_debug_accuracy'},
    { id: 'checkbox_hitsound', key: 'checkbox_hitsound'},
    { id: 'checkbox_models_knife', key: 'checkbox_models_knife'}
    
    
  ];


  const colors = [
    { id: 'glow_enemy_color', key: 'glow_enemy_color' },
    { id: 'glow_friend_color', key: 'glow_friend_color' },
    { id: 'chams_enemy_color', key: 'chams_enemy_color' },
    { id: 'chams_friend_color', key: 'chams_friend_color'},
    { id: 'map_color', key: 'map_color'},
    { id: 'player_fov_range', key: 'player_fov_range'},
    { id: 'player_viewmodel_fov', key: 'player_viewmodel_fov'},
    { id: 'player_viewmodel_x', key: 'player_viewmodel_x'},
    { id: 'player_viewmodel_y', key: 'player_viewmodel_y'},
    { id: 'player_viewmodel_z', key: 'player_viewmodel_z'}
  ];

  const selects = [
    { id: 'select_enemy_glow_style', key: 'select_enemy_glow_style' },
    { id: 'select_friend_glow_style', key: 'select_friend_glow_style' },
    { id: 'select_hitsound_sound', key: 'select_hitsound_sound' },
    { id: 'select_knife_model', key: 'select_knife_model' }
    
  ];

  checkboxes.forEach(checkbox => 
  {
    const element = document.getElementById(checkbox.id);
    element.checked = localStorage.getItem(checkbox.key) === 'true';
  });

  colors.forEach(color => {
  const element = document.getElementById(color.id);
  const savedColor = localStorage.getItem(color.key);
  if (savedColor) {
    element.value = savedColor;}
  });

  selects.forEach(selected => {
    const element = document.getElementById(selected.id);
    const savedSelects = localStorage.getItem(selected.key);
    if (savedSelects) {
      element.value = savedSelects;}
    });



  function sendXHRRequest()
  {
    let data = 
    {
      isAimbotEnabled: document.getElementById('is_aimbot_enabled').checked,
      isTriggerEnabled: document.getElementById('is_trigger_enabled').checked,
      isMiscEnabled: document.getElementById('is_misc_enabled').checked,
      checkboxGlow: document.getElementById('checkbox_glow').checked,
      checkboxGlowEnemy: document.getElementById('checkbox_glow_enemy').checked,
      checkboxGlowFriend: document.getElementById('checkbox_glow_friend').checked,
      colorEnemyGlow: document.getElementById('glow_enemy_color').value,
      glowEnemyStyle: document.getElementById('select_enemy_glow_style').value,
      glowFriendStyle: document.getElementById('select_friend_glow_style').value,
      colorFriendGlow: document.getElementById('glow_friend_color').value,
      checkboxGlowHP: document.getElementById('checkbox_glowHealth').checked,
      checkboxRadar: document.getElementById('checkbox_radar').checked, 
      checkboxChams: document.getElementById('checkbox_chams').checked,
      colorEnemyChams: document.getElementById('chams_enemy_color').value,
      colorFriendChams: document.getElementById('chams_friend_color').value,
      checkboxBhop: document.getElementById('checkbox_bhop').checked,
      checkboxGPreview: document.getElementById('checkbox_gpreview').checked,
      mapColor: document.getElementById('map_color').value,
      darkMap: document.getElementById('checkbox_darkmap').checked,
      playerFOV: document.getElementById('player_fov_range').value,
      playerViewmodel: document.getElementById('checkbox_viewmodel').checked,
      playerViewmodelFOV: document.getElementById('player_viewmodel_fov').value,
      playerViewmodelX: document.getElementById('player_viewmodel_x').value,
      playerViewmodelY: document.getElementById('player_viewmodel_y').value,
      playerViewmodelZ: document.getElementById('player_viewmodel_z').value,
      checkboxRecoilCrosshair: document.getElementById('checkbox_recoil_crosshair').checked,
      checkboxForceSniperCrosshair: document.getElementById('checkbox_force_sniper_crosshair').checked,
      checkboxWeaponDebugAccuracy: document.getElementById('checkbox_weapon_debug_accuracy').checked,
      checkboxHitsound: document.getElementById('checkbox_hitsound').checked,
      selectHitsoundSound: document.getElementById('select_hitsound_sound').value,
      checkboxKnifeModel: document.getElementById('checkbox_models_knife').checked,
      selectKnifeModel: document.getElementById('select_knife_model').value,
    };

    let xhr = new XMLHttpRequest();
    xhr.open('POST', 'http://127.0.0.1/main');
    xhr.setRequestHeader('Content-Type', 'application/json');
    xhr.send(JSON.stringify(data));
    xhr = null;
  }

    sendXHRRequest();

    let apply_button = document.getElementById('apply_button');
    apply_button.addEventListener('click', function() {
    checkboxes.forEach(checkbox => 
    {
      const element = document.getElementById(checkbox.id);
      localStorage.setItem(checkbox.key, element.checked);
    });

    colors.forEach(color => {
    const element = document.getElementById(color.id);
    localStorage.setItem(color.key, element.value);
    });

    selects.forEach(selected => {
      const element = document.getElementById(selected.id);
      localStorage.setItem(selected.key, element.value);
      });

    sendXHRRequest();

  });

  const tabIds = [
    'tab-visuals',
    'tab-aimbot',
    'tab-trigger',
    'tab-misc',
    'tab-configuration',
    'tab-binds'
  ];
  
  const selectIds = [
    'select-visuals',
    'select-aimbot',
    'select-trigger',
    'select-misc',
    'select-configuration',
    'select-binds'
  ];
  
  const createTab = (tabId) => {
    const tabElement = document.getElementById(tabId);
    if (!tabElement) {
      const newTabElement = document.createElement('div');
      newTabElement.id = tabId;
      newTabElement.hidden = true;
      document.body.appendChild(newTabElement);
      return newTabElement;
    }
    return tabElement;
  };
  
  const hideAllTabs = () => {
    tabIds.forEach(tabId => {
      const tabElement = document.getElementById(tabId);
      if (tabElement) {
        tabElement.hidden = true;
      }
    });
  };
  
  const handleSelectClick = (selectId, tabId) => {
    const selectedTab = createTab(tabId);
    hideAllTabs();
    selectedTab.hidden = false;
  };
  
  hideAllTabs();
  
  selectIds.forEach((selectId, index) => {
    const selectElement = document.getElementById(selectId);
    selectElement.addEventListener('click', () => {
      const tabId = tabIds[index];
      handleSelectClick(selectId, tabId);
    });
  });


  let glow = document.getElementById('checkbox_glow');
  const glow_divide = document.querySelectorAll('#glow-divide');

  if (glow.checked === false){
    glow_divide.forEach(element => {
      element.classList.add('hidden-element');
    });}

  else{
    glow_divide.forEach(element => {
      element.classList.remove('hidden-element');
    });}


  glow.addEventListener('click', function() {
    if (glow.checked === false)
    {
      glow_divide.forEach(element => {
        element.classList.add('hidden-element');
      });
    }
    else
    {
      glow_divide.forEach(element => {
        element.classList.remove('hidden-element');
      });
    }
  })

  let chams = document.getElementById('checkbox_chams');
  const chams_divide = document.querySelectorAll('#chams-divide');

  if (chams.checked === false){
    chams_divide.forEach(element => {
      element.classList.add('hidden-element');
    });}

  else{
    chams_divide.forEach(element => {
      element.classList.remove('hidden-element');
    });}


    chams.addEventListener('click', function() {
    if (chams.checked === false)
    {
      chams_divide.forEach(element => {
        element.classList.add('hidden-element');
      });
    }
    else
    {
      chams_divide.forEach(element => {
        element.classList.remove('hidden-element');
      });
    }
  })

  let player_fov_slider = document.getElementById('player_fov_range'); 
  let player_fov_slider_output = document.getElementById('player_fov_slider_output'); 

  let player_viewmodel_x_slider = document.getElementById('player_viewmodel_x');
  let player_viewmodel_y_slider = document.getElementById('player_viewmodel_y');
  let player_viewmodel_z_slider = document.getElementById('player_viewmodel_z');

  let player_viewmodel_x_output = document.getElementById('player_viewmodel_x_output');
  let player_viewmodel_y_output = document.getElementById('player_viewmodel_y_output');
  let player_viewmodel_z_output = document.getElementById('player_viewmodel_z_output');

  let player_viewmodel_fov_slider = document.getElementById('player_viewmodel_fov');
  let player_viewmodel_fov_output = document.getElementById('player_viewmodel_fov_output');

  player_fov_slider.oninput = function() {
    player_fov_slider_output.innerHTML = this.value;
}

player_viewmodel_x_slider.oninput = function() {
  player_viewmodel_x_output.innerHTML = this.value;
}

player_viewmodel_y_slider.oninput = function() {
  player_viewmodel_y_output.innerHTML = this.value;
}

player_viewmodel_z_slider.oninput = function() {
  player_viewmodel_z_output.innerHTML = this.value;
}

player_viewmodel_fov_slider.oninput = function() {
  player_viewmodel_fov_output.innerHTML = this.value;
}