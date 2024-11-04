#include "plugin.hpp"

/* Generateur de square */

float* table_square;
int table_size_square;
int phase_square;

/* Création et remplissage de la table avec un période du signal */
void init_square(float sample_rate, float freq)
{
    table_size_square = (int)(sample_rate / freq);
    printf("table_size_square: %d\n", table_size_square);
    
    /* Alloue dynamiquement une table. */
    table_square = (float*)malloc(table_size_square * sizeof(float));
    
    /* Remplit la table */
    int i;
        // Génération de la 1° moitié
    for (i = 0; i < table_size_square/2; i = i + 1) {
        table_square[i] = -1.f;
    }
        // Génération de la 2° moitié
    for (i = table_size_square/2; i < table_size_square; i = i + 1) {
        table_square[i] = 1.f;
    }
    
    /* Initialise la phase */
    phase_square = 0;
}

void destroy_square()
{
    /* Desalloue le tableau. */
    free(table_square);
}

/* Retourne 1 echantillon et gestion de la phase */
float process_one_sample_square()
{
    float res = table_square[phase_square];
    phase_square = phase_square + 1;
    if (phase_square == table_size_square) {
        phase_square = 0;
    }
    return res;
}

/* Generateur de sinus */

float* table_sinus;
int table_size_sinus;
int phase_sinus;

/* Création et remplissage de la table avec un période du signal */
void init_sinus(int sample_rate, int freq)
{
    table_size_sinus = (int)((float)sample_rate / (float)freq);
    printf("table_size_sinus: %d\n", table_size_sinus);
    
    /* Alloue dynamiquement une table. */
    table_sinus = (float*)malloc(table_size_sinus * sizeof(float));
    
    /* Remplit la table */
    for (int i = 0; i < table_size_sinus; i++) {
        table_sinus[i] = sin(2.f * M_PI * i/(float)table_size_sinus);
    }
    
    /* Initialise la phase */
    phase_sinus = 0;
}

void destroy_sinus()
{
    /* Desalloue le tableau. */
    free(table_sinus);
}

/* Retourne 1 echantillon et gestion de la phase */
float process_one_sample_sinus()
{
    float res = table_sinus[phase_sinus];
    phase_sinus = phase_sinus + 1;
    if (phase_sinus == table_size_sinus) {
        phase_sinus = 0;
    }
    return res;
}

struct MyModule : Module {
    enum ParamId {
        PARAM1_PARAM,
        PARAM2_PARAM,
        PARAM3_PARAM,
        PARAM4_PARAM,
        PARAMS_LEN
    };
    enum InputId {
        INPUT1_INPUT,
        INPUT2_INPUT,
        INPUTS_LEN
    };
    enum OutputId {
        OUTPUT1_OUTPUT,
        OUTPUT2_OUTPUT,
        OUTPUTS_LEN
    };
    enum LightId {
        LIGHTS_LEN
    };

    MyModule()
    {
        config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN, LIGHTS_LEN);
        configParam(PARAM1_PARAM, 0.f, 1.f, 0.f, "");
        configParam(PARAM2_PARAM, 0.f, 1.f, 0.f, "");
        configParam(PARAM3_PARAM, 0.f, 1.f, 0.f, "");
        configParam(PARAM4_PARAM, 0.f, 1.f, 0.f, "");
        configInput(INPUT1_INPUT, "");
        configInput(INPUT2_INPUT, "");
        configOutput(OUTPUT1_OUTPUT, "");
        configOutput(OUTPUT2_OUTPUT, "");
        
        init_square(44100, 600);
        init_sinus(44100, 400);
    }
    
    ~MyModule()
    {
        destroy_square();
        destroy_sinus();
    }

    void process(const ProcessArgs& args) override {
        
        // Genène 2 signaux différent sur les cannaux gauche et droite
        float left = process_one_sample_square();
        float right = process_one_sample_sinus();
        
        outputs[OUTPUT1_OUTPUT].setVoltage(left*5.0f);
        outputs[OUTPUT2_OUTPUT].setVoltage(right*5.0f);
       
        /*
        float pan = params[PARAM1_PARAM].getValue();
        float input = inputs[INPUT1_INPUT].getVoltage();
        
        float left = sqrt(1 - pan) * input;
        float right = sqrt(pan) * input;
        
        outputs[OUTPUT1_OUTPUT].setVoltage(left);
        outputs[OUTPUT2_OUTPUT].setVoltage(right);
        */
    }
    
};

struct MyModuleWidget : ModuleWidget {
    MyModuleWidget(MyModule* module) {
        setModule(module);
        setPanel(createPanel(asset::plugin(pluginInstance, "res/MyModule.svg")));

        addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
        addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
        addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
        addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

        addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(8.002, 21.161)), module, MyModule::PARAM1_PARAM));
        addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(22.705, 21.161)), module, MyModule::PARAM2_PARAM));
        addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(7.877, 42.705)), module, MyModule::PARAM3_PARAM));
        addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(22.92, 42.857)), module, MyModule::PARAM4_PARAM));

        addInput(createInputCentered<PJ301MPort>(mm2px(Vec(8.569, 75.336)), module, MyModule::INPUT1_INPUT));
        addInput(createInputCentered<PJ301MPort>(mm2px(Vec(22.894, 75.336)), module, MyModule::INPUT2_INPUT));

        addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(8.323, 100.332)), module, MyModule::OUTPUT1_OUTPUT));
        addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(22.92, 100.332)), module, MyModule::OUTPUT2_OUTPUT));
    }
};

Model* modelMyModule = createModel<MyModule, MyModuleWidget>("MyModule");
